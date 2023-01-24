import requests
from lxml import etree


def collect(path):
    text = []
    html = requests.get(path, headers={'User-Agent':""}).text
    tree = etree.HTML(html)
    div = tree.xpath('//*[@class="bg-content"]')
    div = div[0]
    heading = div.xpath("./h2")
    p = div.xpath('.//p')
    for node in p:
        para = " ".join([t for t in node.itertext()])
        text.append(para)
    return heading[0].text, text


def main(path_list, file_path):
    content = []
    for path in path_list:
        heading, text_list = collect(path)
        content.append([heading, *text_list])

    with open(file_path, "r", encoding='utf8') as f:
        for i, sec in enumerate(content):
            f.write(f"第{i+1}页\n")
            for line in sec:
                f.write(f"{line}\n")
            f.write("\n\n")
            print(f"finished page {i+1}/{len(content)}")


if __name__ == "__main__":
    main(["http://column.cankaoxiaoxi.com/2014/0711/421215.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_2.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_3.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_4.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_5.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_6.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_7.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_8.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_9.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_10.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_11.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_12.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_13.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_14.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_15.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_16.shtml",
    "http://column.cankaoxiaoxi.com/2014/0711/421215_17.shtml",
    ], "./output.txt")

    