a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

mom = b1*b2
son = a1*b2 + a2*b1

print(son, mom)