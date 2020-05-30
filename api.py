#!/usr/bin/env python3
import time
import json
import requests


"""
# get the algorithm content by name
def get_alg_info(alg_name_slug):
    data = {
        "operationName": "questionData",
        "variables": { "titleSlug": alg_name_slug },
        "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    envInfo\n    libraryUrl\n    __typename\n  }\n}\n"
    }

    resp = requests.post('https://leetcode.com/graphql', json=data)
    ret = resp.json()
    front_id = ret['data']['question']['questionFrontendId']
    return front_id, ret


def fetch_all_alg():
    # get all the algorithm list
    resp = requests.get(url='https://leetcode.com/api/problems/algorithms/')
    # get the json data
    data_json = json.loads(resp.text)
    # get the algorithm list
    alg_list = data_json['stat_status_pairs']

    ret = {}
    for alg_json in alg_list:
        # get the meta info of algorithm
        alg_stat = alg_json['stat']
        #  alg_difficulty = alg_json['difficulty']['level']
        #  alg_paid = alg_json['paid_only']
        alg_name = alg_stat['question__title']
        alg_name_slug = alg_stat['question__title_slug']
        alg_id = alg_stat['question_id']
        #  alg_acs = alg_stat['total_acs']
        #  alg_submitted = alg_stat['total_submitted']
        try:
            #  if alg_id not in range(1, 1109):
            #      continue
            _id, data = get_alg_info(alg_name_slug)
            with open(f'problems/{_id}.{alg_name_slug}.json', 'w') as fh:
                json.dump(data, fh, indent=2)
            time.sleep(0.1)
        except Exception as e:
            print(e)
            print(alg_name_slug)
"""


def get_all_problems():
    resp = requests.get(url='https://leetcode.com/api/problems/all/')
    data = resp.json()
    result = {}
    for item in data['stat_status_pairs']:
        _id = item['stat']['frontend_question_id']
        title_slug = item['stat']['question__title_slug']
        result[_id] = title_slug
    return result


def get_problem_info(title_slug):
    data = {
        "operationName": "questionData",
        "variables": {"titleSlug": title_slug},
        "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    envInfo\n    libraryUrl\n    __typename\n  }\n}\n"
    }

    resp = requests.post('https://leetcode.com/graphql', json=data)
    return resp.json()


if __name__ == '__main__':
    result = get_all_problems()
    with open('problems.json', 'w') as fh:
        json.dump(result, fh, indent=4)
