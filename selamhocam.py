def mazi2022(sayi):
    for i in range(1, sayi + 1):  

        for j in range(sayi - i):
            print(" ", end="")

        for k in range(i):
            print("*", end=" ")
   
        print()

#sayiyi gir hocam f5 e bas

mazi2022(sayi)
