#Single Linked List

##Description

This is my Single Linked List project where I try to implement the datatype in my own way, in a simple and readable(I hope) method. It does not have as purpose to be the most efficient, because it is not destined for any commercial use or work on large amount of data.

##Why are there two versions?
The MainVariant is the one I recommend, as it is the one who works with little to no restriction but has the drawback of everything being in the same file.
The HeaderVariant is a more readable and organized version but if you want to use any datatype as a template besides int, it will be needed to be explicitly defined in the "SingleList.cpp" file (i.e template class SLL<char>). Expect to be slower but as is purpose is to be a proof of concept that is used on small amount of data, it should be unnoticeable.

###How to run the HeaderVariant?
You need to use the following commands in a terminal to make this variant work: "g++ main.cpp SingleList.cpp -o main.exe" and "./main.exe".