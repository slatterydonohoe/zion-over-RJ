from bs4 import BeautifulSoup
from lineup_scraper import LineupScraper

opps = [
    "army",
    "auburn",
    "bc",
    "clemson",
    "cuse",
    "cuse2",
    "cuse3",
    "emich",
    "fsu",
    "fsu2",
    "gt",
    "hartford",
    "indiana",
    "kentucky",
    "louisville",
    "miami",
    "msu",
    "ncstate",
    "ndsu",
    "pitt",
    "princeton",
    "sdsu",
    "stetson",
    "stjohns",
    "texastech",
    "ucf",
    "unc",
    "unc2",
    "unc3",
    "uva",
    "uva2",
    "vt",
    "vt2",
    "wake",
    "wake2",
    "yale",
    "zaga"
]

class PlayByPlayScraper(object):
    def __init__(self, opp):
        self.opp = opp

    def build_plays(self, filename):
        if_ = open("../HTML/" + filename, "r")
        html = if_.read()
        if_.close()
        soup_page = BeautifulSoup(html, 'html.parser')

        return [str.strip(play.getText()) + '\n' for play in soup_page.findAll("td", {"class": "wisbb_bsCPbpDescCol"})]

    def build_1h(self):
        return self.build_plays(self.opp + "_1H.htm")

    def build_2h(self):
        return self.build_plays(self.opp + "_2H.htm")

    def build_ot(self):
        try:
            return self.build_plays(self.opp + "_OT.htm")
        except FileNotFoundError:
            return []


if __name__ == "__main__":
    for opp in opps:
        pbp = PlayByPlayScraper(opp)
        opening_lineup = LineupScraper(opp)
        of_ = open("../data/" + pbp.opp + "_plays.txt", "a")
        of_.write(opening_lineup.create_starting_lineup_change())

        plays_1H = pbp.build_1h()
        if not plays_1H or "lineup change" in plays_1H[0]:
            print("OOPS: First half file is wrong!")
        else:
            for play in plays_1H:
                    of_.write(play)

        plays_2H = pbp.build_2h()
        if not plays_2H or "lineup change" not in plays_2H[0]:
            print("OOPS: Second half file is wrong!")
        else:
            for play in plays_2H:
                of_.write(play)

        plays_OT = pbp.build_ot()
        if plays_OT:
            if plays_OT == plays_1H or plays_OT == plays_2H:
                print("OOPS: OT file mismatch!")
            else:
                print("WOW: Found OT!")
                for play in plays_OT:
                    of_.write(play)
