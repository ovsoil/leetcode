#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re
import click
import os
import shutil
import subprocess

CC = 'clang++'
CFLAGS = '-std=c++11'
INCS = ''
UNITTEST = 'TEST.cpp'
TARGET = 'target'
SRC = 'src'


def build_map():
    qmap = {}
    qid_regex = re.compile('(\d+).*')
    dirs = [d for d in os.listdir(SRC) if os.path.isdir(os.path.join(SRC, d))]
    for folder in dirs:
        qid = qid_regex.search(folder)
        if qid:
            qmap[qid.group(1)] = folder
    return qmap


@click.command()
@click.argument('problem_name')
def gen(problem_name):
    path = os.path.join('src', problem_name)
    if not os.path.exists(path):
        os.mkdir(path)
    open('{}/solution.hpp'.format(path), 'a').close()
    shutil.copy('framework/template/TEST.cpp', '{}/TEST.cpp'.format(path))


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
