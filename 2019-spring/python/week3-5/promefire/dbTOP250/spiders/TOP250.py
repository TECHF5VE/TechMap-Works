# -*- coding: utf-8 -*-
import scrapy
from dbTOP250.items import Dbtop250Item
from scrapy.http import Request
import time,random

class Top250Spider(scrapy.Spider):
    name = 'TOP250'
    allowed_domains = ['movie.douban.com']
    start_urls = []
    for x in range(0,11):
        m = 'https://movie.douban.com/top250?start=' + str(25*x) + '&filter='
        start_urls.append(m)
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:68.0) Gecko/20100101 Firefox/68.0'
    }

    def parse(self, response):
        node_list=response.xpath('//ol[@class="grid_view"]/li')
        priority = 3000
        for x in node_list:
            xurl = x.xpath('.//a/@href').extract()
            time.sleep(random.random()*3)
            priority -= 100
            yield Request(xurl[0],callback=self.parse_details,headers=self.headers,priority=priority)

    def parse_details(self,response):
        name = response.xpath('//span[@property="v:itemreviewed"]/text()').extract()
        score = response.xpath('//strong[@class="ll rating_num"]/text()').extract()
        details = response.xpath('//span[@property="v:summary"]/text()').extract()
        j = details[0].replace('\n','')
        j = details[0].strip()
        item = Dbtop250Item()
        item['name']=name[0]
        item['score'] =score[0]
        item['details'] = j
        yield item


