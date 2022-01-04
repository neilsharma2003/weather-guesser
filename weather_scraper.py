from requests_html import HTMLSession
s = HTMLSession()

query = input("Input city of weather you'd like to guess: ")
url = f'https://www.google.com/search?q=weather+{query}'
r = s.get(url)

with open('readme.txt', 'w') as f:
    f.write(r.html.find('span#wob_tm', first=True).text)






