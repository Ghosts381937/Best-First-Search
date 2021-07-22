# Best-First-Search
![image](https://github.com/Ghosts381937/Best-First-Search/blob/master/unknown%20(1).png)  

不同於BFS、DFS以廣度或深度進行搜尋，best-first search則是以路徑的權重優先做搜尋  

pseudocode: 
```
建立一個Pirority queue = pq  
將起點放入pq  
while(pq不為空)  
  從pq取出一個節點node並從pq刪除該節點  
  if(node是終點)  
    結束迴圈  
  else  
    for 每個node的相鄰節點  
      if(相鄰節點未走訪)  
      將相鄰節點讓入pq  
      相鄰節點設為已走訪  
```
  
範例:  
以文首的圖做舉例  
start = A,goal = H,pq{A}  
1.node = A pq{}  =>  pq{BCD}  
2.node = B pq{CD}  =>  pq{CED}  
3.node = C pq{ED}  =>  pq{EDF}  
4.node = E pq{DF}  =>  pq{DFG}  
5.node = D pq{FG}  =>  pq{FG}  
6.node = F pq{G}  => pq{HG}  
7.node = H pq{G}  => goal was found  
  
範例輸入及輸出以供測試:  
![image](https://github.com/Ghosts381937/Best-First-Search/blob/master/unknown.png)
