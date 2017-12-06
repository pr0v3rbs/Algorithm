arr = raw_input()

result = 0
for idx, data in enumerate(arr):
    if arr[(idx + 1) % len(arr)] == data:
        result += int(data)

print result
