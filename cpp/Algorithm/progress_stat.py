stat = [
[11.6],
    [2.4,
    11.0,
    11.5,
    7.5,
    3.6,
    5.8,
    17.0,
    19.6,
    26.4,
    16.4,
    8.6,
    13.9,
    10.5,
    13.2,
    15.3,
    18.5,
    8.4,
    7.6],
    [23.2,
    7.5,
    13.9,
    7.4,
    11.5,
    10.7,
    24.6,
    22.7,
    14.3,
    16.2,
    10.8,
    12.9,
    15],
    [26.7,
    17.1,
    13.4,
    24.2,
    15.2,
    9.1,
    7.4,
    15.4,
    7.5,
    8.1,
    13.3,
    9.8,
    5.1,
    9.3,
    9.6,
    16.8,
    6.0,
    16.4],
    [4.3, 21.3,18.9,9.3,10.1,9.2,17.4,15.4,20.9,8.1,10.1,11.6,12.4,5.5,9.7,16.2,4.1,5.2,9.2,8.5,9.9,7.7,11.9],
    [9.9,7.7,4.7,10.3,7.7,7.3,5.7,6.7,5.1,11.1,7.6,4.5,9.8,7.2,6.5],
    [18.6,22.1,13.5,10.9,6.5],
    [22.1,8.3,10.9,6.1,13.4,9.7,16.2,19.1, 10.4,9.2,10.1,8.5,23.5,17.1,10.8,25.2]
]

used = [
    6,
    186,
    138,
    2.6 * 60,
    12,
    180,
    0,
    42,
    36
]


watched = sum(used)

total = 0
for l in stat:
    if l:
        t = sum(l)
        print(t)
        total += t
print(sum(used)/total);
