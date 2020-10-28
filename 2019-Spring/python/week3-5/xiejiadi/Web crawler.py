import requests
import re
import json


class MovieTop(object):
    def __init__(self):
        self.movieName = []
        self.movies_brief = []
        self.movieList = []

    def get_page_info(self):
        start_page = 0
        while start_page <= 225:
            website = 'https://movie.douban.com/top250' + "?start=" + str(start_page) + "&filter="
            get_page = requests.get(website)
            get_page_str = get_page.text
            pattern = re.compile(u'<div.*?class="item">.*?'
                                 + u'<div.*?class="info">.*?'
                                 + u'<div.*?class="hd">.*?'
                                 + u'<a href="(.*?)".*?class="">.*?'
                                 + u'<span.*?class="title">(.*?)</span>.*?'
                                 + u'<div.*?class="bd">.*?'
                                 + u'<div.*?class="star">.*?'
                                 + u'<span.*?class="rating_num".*?property="v:average">'
                                 + u'(.*?)</span>.*?'
                                 , re.S)
            movies = re.findall(pattern, get_page_str)
            for movie in movies:
                self.movieName.append([movie[1],
                                       movie[2],
                                       movie[0]])
            start_page += 25

    def get_brief_info(self):
        pattern1 = re.compile(r'<span property="v:summary".*?>(.*?)</span>', re.S)
        for movie in self.movieName:
            response1 = requests.get(movie[2])
            get_brief = response1.text
            movie_brief = re.findall(pattern1, get_brief)
            movies_str = ''.join(movie_brief)
            movie1 = movies_str.replace('\n', '')
            movie2 = movie1.replace('\u3000\u3000', '')
            movie3 = movie2.replace('<br />', '')
            movies_str = movie3.replace(' ', '')
            self.movies_brief.append(movies_str)
            # 查看进度
            print(movies_str)
    
    def append_list(self):
        x = 0
        for movie in self.movieName:
            self.movieList.append(["电影名称：" + movie[0],
                                   "电影评分：" + movie[1],
                                   "电影url：" + movie[2],
                                   "电影简介：" + self.movies_brief[x]])
            print(self.movieList[x])
            x += 1

    def write_page(self):
        print("开始写入文件...")
        file = open('./DoubanTop250.json', 'w')
        try:
            json.dump(self.movieList, file)
            print("成功写入文件...")
        finally:
            file.close()


movies = MovieTop()
movies.get_page_info()
movies.get_brief_info()
movies.append_list()
movies.write_page()

