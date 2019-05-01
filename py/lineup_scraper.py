from bs4 import BeautifulSoup

lastToFullDict = {
    "Jones": "Tre Jones",
    "Williamson": "Zion Williamson",
    "Barrett": "R.J. Barrett",
    "Reddish": "Cam Reddish",
    "DeLaurier": "Javin DeLaurier",
    "Goldwire": "Jordan Goldwire",
    "Bolden": "Marques Bolden",
    "Besser": "Brennan Besser",
    "Robinson": "Justin Robinson",
    "Vrankovic": "Antonio Vrankovic",
    "White": "Jack White",
    "O'Connell": "Alex O'Connell",
    "Buckmire": "Mike Buckmire",
    "Baker": "Joey Baker"
}

class LineupScraper(object):
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

        print(title)
        if "Duke Blue Devils vs." in title:
            lineup = lineups[0]
        elif "vs. Duke Blue Devils" in title:
            lineup = lineups[1]

        players = lineup.findAll("a")
        i = 0
        while i < 5:
            starters = [lastToFullDict[p.getText()] for p in players[0:5]]
            i += 1
        return starters

    def create_starting_lineup_change(self):
        lineup_list = self.find_starters()
        lineup_string = "Blue Devils lineup change (" + ", ".join(lineup_list) + ")\n"
        return lineup_string

def main():
    lineup_scraper = LineupScraper("yale")


if __name__ == "__main__":
    main()

