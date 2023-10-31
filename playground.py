# ini script buat automate ngoding... some part :v
for i in range(1, 29):
    print(f"else if(strCompare(input[0].TabWord, command[{i}]))", end="")
    print("{",end="\n")
    print(f"\tprintf(\"called %s\\n\", command[{i}]);", end="\n")
    print("}")
