BT ,WT,TAT, TotalWT=[],[0],[],0
N=int(input("Enter Number Of Process - "))

print("Enter Burst Time Of processes -")
for x in range(N): BT.append(int(input()))
BT.sort()

print("BT  WT  TAT")
for i in range(N) :
  if i>0:
        WT.append(  WT[i-1] + BT[i-1])
  TotalWT+=WT[i]
  TAT.append(BT[i] +  WT[i])
  print(BT[i]," ",WT[i], " ",TAT[i]) 

print("Average Burst Time is -",TotalWT/N)
