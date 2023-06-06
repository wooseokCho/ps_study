select N, 
CASE 
  when N = any (select N from BST where P is NULL) then "Root"
  when N = any( select P from BST) then "Inner"
  else "Leaf"
END 
from BST order by N; 
