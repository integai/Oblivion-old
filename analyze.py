import json

with open('testData.json') as file:
    data = json.load(file)

turbo_transactions_count = sum(1 for item in data if item['Chosen Algorithm'] == 'Turbo Transactions: High load')
normal_mode_count = sum(1 for item in data if item['Chosen Algorithm'] == 'Normal Mode: Moderate load')
single_transactions_count = sum(1 for item in data if item['Chosen Algorithm'] == 'Single Transactions: Low load')

print(f'The number of Turbo Transactions cases: {turbo_transactions_count}')
print(f'The number of Normal Mode cases: {normal_mode_count}')
print(f'The number of Single Transactions cases: {single_transactions_count}')

