# Text file dumper
from subprocess import call
import re

address = raw_input("URL: ")

# Grabs the raw html of the page
def get_html(address):
    call(["wget", address, "-O", "toread.txt"])
    with open("toread.txt") as source:
        html = source.read()
    return html

# Searches for all assosiated text files and links to "go deeper"
def link_search(html):
    endings = re.findall(r"HREF=\"(.+)\"", html)
    endings = [ending for ending in endings if not (ending.endswith(".html") or ending.endswith(".com"))]
    return endings

def dump(address, endings):
    with open("wget_list.txt", "w+") as urllist:
        links = [address + end for end in endings]
        for link in links:
            urllist.write(link + "\n")
    call(["wget", "-i", "wget_list.txt"])


initalhtml = get_html(address)
initallinks = link_search(initalhtml)

for link in initallinks:
    deephtml = get_html("http://www.textfiles.com/"+link)
    deep_endings = link_search(deephtml)
    dump("http://www.textfiles.com/" + link + "/", deep_endings)
    print link