import json

# Read the JSON file
with open('config.json') as f:
    data = json.load(f)

# Print the JSON data in a stylish format
print('## Configuration')
for key, value in data.items():
    print('* {}: {}'.format(key, value))

