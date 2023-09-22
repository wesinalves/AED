import random

def busca_linear(vet, alvo):
    i = 0
    t = len(vet)
    while(i < t and vet[i] != alvo):
        i += 1
    return False if i == t else True
        
if __name__ == "__main__":
    # create a random vector
    vetor = [random.randint(0, 100) for _ in range(10)]
    for v in vetor:
        print(v, end='\t')
    # sort a number
    while(1):
        alvo = input("Digite um alvo (-1 para sair): ")
        res = busca_linear(vetor, int(alvo))
        print(res)
        if alvo == -1:
            break
