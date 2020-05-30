#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re
import json
import click
import os
import subprocess

import api

CC = 'clang++'
CFLAGS = '-std=c++14'
INCS = ''
UNITTEST = 'TEST.cpp'
TARGET = 'target'
SRC = 'src'
PROBLEMS = 'problems'


def build_map():
    qmap = {}
    qid_regex = re.compile(r'(\d+).*')
    dirs = [d for d in os.listdir(SRC) if os.path.isdir(os.path.join(SRC, d))]
    for folder in dirs:
        qid = qid_regex.search(folder)
        if qid:
            qmap[qid.group(1)] = folder
    return qmap


@click.command()
@click.argument('problem_id')
def gen(problem_id):
    with open('problems.json', 'r') as fh:
        data = json.load(fh)
    title_slug = data.get(problem_id)
    if title_slug is None:
        data = api.get_all_problems()
        title_slug = data.get(problem_id)
        if title_slug is None:
            print(f"No Problem with id = {problem_id}")
            return

    path = os.path.join('src', f'{problem_id}.{title_slug}')
    if os.path.exists(path):
        print(f"Problem {title_slug} exist!")
        return

    info = api.get_problem_info(title_slug)
    snippet = ''
    for snp in info['data']['question']['codeSnippets']:
        if snp['lang'] == 'C++':
            snippet = snp['code']
            break
    tags = [tag['name'] for tag in info['data']['question']['topicTags']]
    title = info['data']['question']['title']
    meta = json.loads(info['data']['question']['metaData'])
    func_name = meta.get('name', 'function_name')

    os.mkdir(path)
    with open('{}/solution.hpp'.format(path), 'a') as fh:
        fh.write(snippet)
    with open('framework/template/TEST.cpp', 'r') as fh:
        test_content = fh.read()
    with open(os.path.join(path, 'TEST.cpp'), 'w') as fh:
        fh.write(test_content.replace(
            'Testcase doc string', title).replace(
                '[tag]', ''.join([f'[{tag}]' for tag in tags])).replace(
                    'function_name', func_name))


@click.command()
@click.option('--debug', '-d', is_flag=True)
@click.argument('problem_id')
def test(problem_id, debug):
    click.echo('Test Start...')

    qmap = build_map()
    if problem_id not in qmap:
        print("There is no solution with problem id: {}".format(problem_id))
        return
    cwd = os.path.join(SRC, qmap[problem_id])

    def run_command(args):
        return subprocess.call(args, cwd=cwd)

    compile_cmd = [CC, UNITTEST, '-o', TARGET, INCS, CFLAGS]
    if debug:
        compile_cmd += ['-DDEBUG']

    not run_command(compile_cmd) and run_command(['./{}'.format(TARGET)])
    run_command(['rm', TARGET])


@click.group()
def cli():
    pass


if __name__ == '__main__':
    cli.add_command(gen)
    cli.add_command(test)
    cli()
