from bs4 import BeautifulSoup


class PlayByPlayParser(object):
    def __init__(self, opp):
        self.opp = opp

    def build_1h(self):
        f = open("../HTML/" + self.opp + "_1H.htm", "r")
        html = f.read()
        f.close()
        soup_page = BeautifulSoup(html, 'html.parser')

        plays = [play.getText() for play in soup_page.findAll("td", {"class" : "wisbb_bsCPbpDescCol"})]

        print(plays)

if __name__ == "__main__":
    pbp = PlayByPlayParser("yale")
    pbp.build_1h()