import csv
import json

csvfile = open('/Users/Kishan/Documents/UC Davis/Spring 2018/ECS 170/Project/ECS170/part1.csv', 'r')
jsonfile = open('/Users/Kishan/Documents/UC Davis/Spring 2018/ECS 170/Project/ECS170/part1.json', 'w')

fieldnames = ("filename","build","map_name","game_duration_loops","players","P1-outcome","P1-race","P1-apm","P2-race","P2-apm")
reader = csv.DictReader( csvfile, fieldnames)
for row in reader:
    json.dump(row, jsonfile)
    jsonfile.write('\n')