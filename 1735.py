a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

mom = b1*b2
son = a1*b2 + a2*b1

if mom < son:
    min_num = int(mom/2) + 1
else:
    min_num = int(son/2) + 1

for i in range(1, min_num + 1):
    if mom%i==0 and son%i==0:
        mom /= i
        son /= i

print(int(son), int(mom))