#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <queue>
#include <string>
#include <sstream>

class JogoQC {
    
    int jogadas;
    int table_size;
    int zero_pos;
    std::vector<int> qb;
    std::vector<char> movs;
    
    public:
        JogoQC(): table_size(3), jogadas(0), zero_pos(0) {
            for(int i=0;i<9;i++) qb.push_back(i);
        }

        JogoQC(int var): table_size(var), jogadas(0), zero_pos(0) {
            for(int i=0;i<(table_size*table_size);i++) qb.push_back(i);
        }

        void embaralhar() {
            std::random_shuffle(qb.begin(), qb.end());
        }

        void zerarJogadas() {
            movs.clear();
            jogadas = 0;
        }

        bool checarObjetivo() {
            bool obj = true;
            for(int i=0;i<table_size*table_size;i++) {
                obj = obj && (qb[i] == i);
                if(!obj) return false;
            } return true; // Vitória;
        }

        JogoQC moverCima() {
            JogoQC nj = *this;
            
            if(nj.zero_pos/nj.table_size == 0) return nj;

            nj.qb[nj.zero_pos] = nj.qb[nj.zero_pos-nj.table_size];
            nj.qb[nj.zero_pos-nj.table_size] = 0;
            
            nj.zero_pos = nj.zero_pos-nj.table_size;
            nj.movs.push_back('C');
            nj.jogadas++;
            return nj;
        }

        JogoQC moverBaixo() {
            JogoQC nj = *this;
            
            if(nj.zero_pos/nj.table_size == nj.table_size - 1) return nj;

            nj.qb[nj.zero_pos] = nj.qb[nj.zero_pos+nj.table_size];
            nj.qb[nj.zero_pos+nj.table_size] = 0;
            
            nj.zero_pos = nj.zero_pos+nj.table_size;
            nj.movs.push_back('B');
            nj.jogadas++;
            return nj;
        }

        JogoQC moverEsquerda() {
            JogoQC nj = *this;
            
            if(nj.zero_pos%nj.table_size == 0) return nj;

            nj.qb[nj.zero_pos] = nj.qb[nj.zero_pos-1];
            nj.qb[nj.zero_pos-1] = 0;
            
            nj.zero_pos = nj.zero_pos-1;
            nj.movs.push_back('E');
            nj.jogadas++;
            return nj;
        }

        JogoQC moverDireita() {
            JogoQC nj = *this;
            
            if(nj.zero_pos%nj.table_size == table_size - 1) return nj;

            nj.qb[nj.zero_pos] = nj.qb[nj.zero_pos+1];
            nj.qb[nj.zero_pos+1] = 0;
            
            nj.zero_pos = nj.zero_pos+1;
            nj.movs.push_back('D');
            nj.jogadas++;
            return nj;
        }

        bool operator==(JogoQC outro) {
            bool igual = true;
            for(int i=0;i<table_size*table_size;i++) {
                igual = igual && (outro.qb[i] == this->qb[i]);
                if(!igual) return false;
            } return igual;
        }

        bool operator!=(JogoQC outro) {
            return !(*this == outro);
        }

        bool operator>(JogoQC outro) const {
            if(this->jogadas < outro.jogadas) return true;
            else if(this->jogadas > outro.jogadas) return false;
            else { // Teste dos numeros, menor na posição 0, por ai vai;
                for(int i=0;i<table_size*table_size;i++) {
                    if(this->qb[i] > outro.qb[i]) return false;
                    else if(this->qb[i] < outro.qb[i]) return true;
                }
            } // Se passou tudo isso, e foi tudo igual, então é false!

            return false;
        }

        bool operator<(JogoQC outro) const {
            return outro > *this;
        }

        JogoQC solucionar() {
            bool status = checarObjetivo();
            std::queue<JogoQC> jogos;
            std::set<JogoQC> jogos_anteriores;
            jogos.push(*this);
            JogoQC jg;
            while(!status) {
                jg  = jogos.front();
                JogoQC jgm = jg.moverCima();

                jogos.pop();

                if(jg != jgm && (jogos_anteriores.find(jgm) == jogos_anteriores.end())) {
                    jogos_anteriores.insert(jgm);
                    jogos.push(jgm);
                }

                jgm = jg.moverBaixo();

                if(jg != jgm && (jogos_anteriores.find(jgm) == jogos_anteriores.end())) {
                    jogos_anteriores.insert(jgm);
                    jogos.push(jgm);
                }

                jgm = jg.moverDireita();

                if(jg != jgm && (jogos_anteriores.find(jgm) == jogos_anteriores.end())) {
                    jogos_anteriores.insert(jgm);
                    jogos.push(jgm);
                }

                jgm = jg.moverEsquerda();

                if(jg != jgm && (jogos_anteriores.find(jgm) == jogos_anteriores.end())) {
                    jogos_anteriores.insert(jgm);
                    jogos.push(jgm);
                }

                status = jg.checarObjetivo();
            }

            return jg;
        }

        std::string resultadosDosMovimentos() {
            std::ostringstream sos;
            sos << "JOGADAS: " << jogadas << std::endl;
            for(int i=0;i<jogadas;i++) sos << movs[i] << " ";
            return sos.str();   
        }

        friend std::ostream &operator<<(std::ostream &os, const JogoQC &jogo) {
            for(int i=0;i<jogo.table_size;i++) {
                for(int j=0;j<jogo.table_size;j++) {
                    os << jogo.qb[j+jogo.table_size*i] << "  ";
                } os << std::endl;
            } return os;
        }
};


int main() {
    srand(time(nullptr));
    JogoQC jogo(3);
    //jogo.embaralhar();
    jogo = jogo.moverBaixo();
    jogo = jogo.moverBaixo();
    jogo.zerarJogadas();
    std::cout << jogo << std::endl;
    JogoQC solucao = jogo.solucionar();
    std::cout << solucao << std::endl << solucao.resultadosDosMovimentos() << std::endl;
    return 0;
}