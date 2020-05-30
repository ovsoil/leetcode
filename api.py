#!/usr/bin/env python3
import requests


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


def get_problem_info_zh(title_slug):
    data = {
        "operationName": "questionData",
        "variables": {"titleSlug": title_slug},
        "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    envInfo\n    book {\n      id\n      bookName\n      pressName\n      source\n      shortDescription\n      fullDescription\n      bookImgUrl\n      pressImgUrl\n      productUrl\n      __typename\n    }\n    isSubscribed\n    isDailyQuestion\n    dailyRecordStatus\n    editorType\n    ugcQuestionId\n    __typename\n  }\n}\n"
    }
    resp = requests.post('https://leetcode-cn.com/graphql/', json=data)
    return resp.json()


if __name__ == '__main__':
    import json
    result = get_all_problems()
    with open('problems.json', 'w') as fh:
        json.dump(result, fh, indent=4)
    #  result = get_problem_info_zh('')
    #  with open('data.json', 'w') as fh:
    #      json.dump(result, fh, indent=4)
    #  with open('data.html', 'w') as fh:
    #      fh.write(result['data']['question']['content'])
    #  title_zh = result['data']['question']['translatedTitle'].replace(' ', '-')
    #  with open(f'{title_zh}.html', 'w') as fh:
    #      fh.write(result['data']['question']['translatedContent'])
