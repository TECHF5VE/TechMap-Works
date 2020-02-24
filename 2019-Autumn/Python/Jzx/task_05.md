```python
import json
import time

import requests
from lxml import etree
from selenium import webdriver
from selenium.webdriver.chrome.options import Options


def catch(html, num):
    q_position = html.xpath('//ul[@class="item_con_list"]/li[@data-index={}]/@data-positionname'.format(num))
    q_company = html.xpath('//ul[@class="item_con_list"]/li[@data-index={}]/@data-company'.format(num))
    q_salary = html.xpath('//ul[@class="item_con_list"]/li[@data-index={}]/@data-salary'.format(num))
    q_address = html.xpath('//ul[@class="item_con_list"]/li[@data-index={}]/div/div/div/a/span/em/text()'.format(num))
    q_acquire = html.xpath('//ul[@class="item_con_list"]/li[@data-index={}]/div/div/div/div/text()'.format(num))
    q_list = [q_position, q_company, q_salary, q_address, q_acquire]
    return q_list


def main():
    my_headers = {
        'Host': 'www.lagou.com',
        'Connection': 'keep-alive',
        'Cache-Control': 'max-age=0',
        'Upgrade-Insecure-Requests': '1',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.116 Safari/537.36',
        'Sec-Fetch-Dest': 'document',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
        'Sec-Fetch-Site': 'none',
        'Sec-Fetch-Mode': 'navigate',
        'Sec-Fetch-User': '?1',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'zh-CN,zh;q=0.9',
        'Cookie': 'JSESSIONID=ABAAABAABFIAAACF349565AE0082D7C57AD7D5CFA68710D; user_trace_token=20200224120700-7aadea2c-fcc5-4606-b1f6-dfe73e802fb5; WEBTJ-ID=20200224120701-170756076f6586-0aebf74550852-313f68-1327104-170756076f7466; PRE_UTM=; PRE_HOST=; PRE_LAND=https%3A%2F%2Fwww.lagou.com%2Fzhaopin%2F; LGSID=20200224120701-741a75ba-e2b5-42a0-b8c2-2a48d2c43857; PRE_SITE=; LGUID=20200224120701-e84742f5-61b4-437b-a2aa-e6ab9f1bed16; X_HTTP_TOKEN=94ddea992ed532ec12271528515d70db9174d6b137; _ga=GA1.2.1409413932.1582517221; _gat=1; LGRID=20200224120701-ff9527ff-530d-42ce-ac55-b5288a7ec909; SEARCH_ID=b573eb81f199467a84919d59998b1465'
    }
    url = "https://www.lagou.com/zhaopin/"
    for n in range(1, 31):
        my_url = url + str(n)
        r = requests.get(url=my_url, headers=my_headers)
        html = etree.HTML(r.text)
        for i in range(15):
            data = json.dumps(catch(html=html, num=i), ensure_ascii=False)
            with open('./data.json', 'a+', encoding='utf-8') as f:
                f.write(data)
                f.write('\n')
        time.sleep(1)

        
if __name__ == '__main__':
    main()

```

