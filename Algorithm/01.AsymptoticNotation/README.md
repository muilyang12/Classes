# Asymptotic notation, 점근 성능 표기법

- Big-O
  - If f(n)≤c·g(n), it is said that the algorithm has an asymptotic performance of f(n)=O(g(n)).
  - It represents the worst-case time complexity of an algorithm, indicating that our algorithm cannot take longer than this. (Asymptotic upper bound)

- BIG-Omega
  - If f(n)≥c·g(n), it is said that the algorithm has an asymptotic performance of f(n)=Ω(g(n)).
  - It represents the best-case time complexity of an algorithm (Asymptotic lower bound)

- BIG-Theta
  - If c1·g(n)≤f(n)≤c2·g(n), it is said the algorithm has an asymptotic performance of f(n)=Θ(g(n)).
  - It represents the tight bound between the best-case and worst-case time complexity of an algorithm (Asymptotic tight bound)
