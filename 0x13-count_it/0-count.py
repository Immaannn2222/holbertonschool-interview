#!/usr/bin/python3
"""INTERVIEW"""
import requests


def count_words(subreddit, word_list, after="", count_dict={}):
    """recursive function that queries the Reddit API"""
    if len(count_dict) <= 0:
        for item in word_list:
            count_dict[item.lower()] = 0

    if after is None:
        sorted_dict = dict(sorted(
            count_dict.items(),
            key=lambda x: (-x[1], x[0])
            ))
        for k, v in sorted_dict.items():
            if v > 0:
                print("{}: {}".format(k, v))
        return None
    url = "https://api.reddit.com/r/{}/hot".format(subreddit)
    params = {'limit': 100, 'after': after}
    headers = {'user-agent': 'xxxx'}
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return None
    try:
        j_resp = response.json()
    except ValueError:
        return None
    try:
        data = j_resp.get("data")
        after = data.get("after")
        posts = data.get("children")
        for child in posts:
            core = child.get("data")
            title = (core.get("title").lower()).split()
            for w in word_list:
                count_dict[w] += title.count(w.lower())
    except Exception:
        return None

    count_words(subreddit, word_list, after, count_dict)
