# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy

class Dbtop250Item(scrapy.Item):
    # define the fields for your item here like:
    name = scrapy.Field()  # 电影名字
    score = scrapy.Field()  # 豆瓣分数
    details = scrapy.Field() #剧情简介
    #id = scrapy.Field()

