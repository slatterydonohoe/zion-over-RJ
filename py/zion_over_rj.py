from bs4 import BeautifulSoup

f = open("../HTML/yale_lineup.htm", "r")
html = f.read()
f.close()
soupPage = BeautifulSoup(html, 'html.parser')

#title = soupPage.find("meta", {"property" : "og:description"}).content
title = soupPage.title.get_text()
lineups = soupPage.findAll("table", {"class" : "wisbb_bsStandard"})
lineup = 0

print(title)
if "Duke Blue Devils vs." in title:
    lineup = lineups[0]
elif "vs. Duke Blue Devils" in title:
    lineup = lineups[1]

starters = []
if lineup != 0:
    players = lineup.findAll("a")
    i = 0
    while i < 5:
        starters = [p.getText() for p in players[0:5]]
        #print(players[i].get_text())
        i += 1
    print(starters)

