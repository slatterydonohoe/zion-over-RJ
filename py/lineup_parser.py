from bs4 import BeautifulSoup


class LineupParser(object):
    def __init__(self, opp):
        self.opp = opp

    def find_starters(self):
        f = open("../HTML/" + self.opp + "_lineup.htm", "r")
        html = f.read()
        f.close()
        soup_page = BeautifulSoup(html, 'html.parser')

        title = soup_page.title.get_text()
        lineups = soup_page.findAll("table", {"class" : "wisbb_bsStandard"})
        lineup = 0

        if "Duke Blue Devils vs." in title:
            lineup = lineups[0]
        elif "vs. Duke Blue Devils" in title:
            lineup = lineups[1]

        players = lineup.findAll("a")
        i = 0
        while i < 5:
            starters = [p.getText() for p in players[0:5]]
            i += 1
        print(starters)

def main():
    lp = LineupParser("yale")
    lp.find_starters()

if __name__ == "__main__":
    main()

