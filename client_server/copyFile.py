with open("clientFile.txt","w") as f:
    for i in range(50000):
        f.write("Hello World, This file size is > 1MB\n")
