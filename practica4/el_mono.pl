
lugar(puerta).
lugar(ventana).
lugar(centro).

% La banana en el centro
banana(centro).

% Estado final
meta(estado(_, _, _, si)).

% Caminar 
accion(estado(M, C, no, B),
       caminar(M, X),
       estado(X, C, no, B)) :-
    lugar(X),
    X \= M.

% Empujar caja (solo si está con la caja)
accion(estado(M, M, no, B),
       empujar(M, X),
       estado(X, X, no, B)) :-
    lugar(X),
    X \= M.

% Subirse a la caja
accion(estado(M, M, no, B),
       subir,
       estado(M, M, si, B)).

% Bajar
accion(estado(M, M, si, B),
       bajar,
       estado(M, M, no, B)).


accion(estado(centro, centro, si, no),
       agarrar,
       estado(centro, centro, si, si)).


resolver(EstadoInicial, Pasos) :-
    buscar(EstadoInicial, [EstadoInicial], Pasos).

buscar(Estado, _, []) :-
    meta(Estado).

buscar(Estado, Visitados, [Accion | Resto]) :-
    accion(Estado, Accion, NuevoEstado),
    \+ member(NuevoEstado, Visitados),
    buscar(NuevoEstado, [NuevoEstado | Visitados], Resto).