# random-walk-cycle-graph-tikz

generates TeX source code that draws a directed graph depicting random walk on a circle with radius r with n states using tikzpicture

actually dont use this; instead, do this:

\begin{tikzpicture}[->,auto,semithick]
        \draw \foreach \x in {0,360/n,...,(360-360/n)}
        {
            (\x:r) node {}  -- (\x+36:r)
        };
\end{tikzpicture}

(replacing n and r)
