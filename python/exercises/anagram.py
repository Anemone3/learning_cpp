s = "arca"
t = "cara"


def anagram(s, t):
    if len(s) != len(t):
        return False
    # char int list (lo usaremos para insertar datos en los indices, -1 o 1, si la letra
    # por ejemplo s[i] -> 'a' -> ord('a') -> 97 -> 97 - ord('a') -> 0 -> count[0] + 1)
    # y asi, llegara un punto donde t[i] -> ord('a') -> 97 - 97 -> 0 -> count[0] - 1)
    # al final verificamos que count tenga valores 0, si no todos son 0 retorna false
    count = [0] * 26
    max_len = len(s)
    for indice in range(max_len):
        # ord('a') => 97
        a_1 = ord(s[indice])
        a_2 = ord(t[indice])
        print("1 letter:", s[indice], "-> ", a_1)
        print("2 letter:", t[indice], "-> ", a_2)

        b_1 = a_1 - ord("a")
        b_2 = a_2 - ord("a")

        print("s:", s[indice], "->", b_1)
        print("t:", t[indice], "->", b_2)
        print("antes -> ", count)

        count[b_1] += 1
        count[b_2] -= 1

        print("despues -> ", count)

    return all(c == 0 for c in count)


print(anagram(s, t))
