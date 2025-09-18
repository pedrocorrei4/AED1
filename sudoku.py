def verificar_sudoku(matriz):
    def contem_1_a_9(lista):
        return sorted(lista) == list(range(1, 10))
    
    for linha in matriz:
        if not contem_1_a_9(linha):
            return False
    
    for col in range(9):
        coluna = [matriz[linha][col] for linha in range(9)]
        if not contem_1_a_9(coluna):
            return False
    
    for box_linha in range(0, 9, 3):
        for box_col in range(0, 9, 3):
            bloco = []
            for i in range(3):
                for j in range(3):
                    bloco.append(matriz[box_linha + i][box_col + j])
            if not contem_1_a_9(bloco):
                return False
    
    return True
def main():
    n = int(input())
    for instancia in range(1, n + 1):
        matriz = [list(map(int, input().split())) for _ in range(9)]
        print(f"Instancia {instancia}")
        if verificar_sudoku(matriz):
            print("SIM")
        else:
            print("NAO")
        print()
if __name__ == "__main__":
    main()