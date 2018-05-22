import csv
import json

csvfile = open('filename.csv', 'r') #specify directory and csv filename for input
jsonfile = open('filename.json', 'w') #specify directory and json filename for output

fieldnames = ("filename","build","map_name","game_duration_loops","players","P1-outcome","P1-race","P1-apm","P2-race","P2-apm")
reader = csv.DictReader( csvfile, fieldnames)
for row in reader:
    json.dump(row, jsonfile)
    jsonfile.write('\n')