// Tempura Simulada!
import java.util.Random;
import java.lang.Math;
//

public class Tabuleiro {
    
    private int size;
    private int stats[][];
    private int queen_pos[];
    private Random gen;
    private double alfa;
    public double Temp;
    

    public Tabuleiro(int size) {
        this.size = size;
        this.stats = new int[size][size];
        this.queen_pos = new int[size];
        for(int i=0;i<size;i++) {
            for(int j=0;j<size;j++) 
                this.stats[i][j] = 0;
            
            queen_pos[i] = 0; // j; 
        }

        //
        //    TEMPURA SIMULADA
        this.gen  = new Random();
        this.alfa = 0.98;
        this.Temp = 10000000;

        //
    }

    public void movQueenTo(int queen_p, int new_position) {
        this.queen_pos[queen_p] = new_position;
    }

    // HEURISTICA;

    public int getQueenPairs(int queen_p, int new_column) {
        int line = queen_p, column = this.queen_pos[queen_p];
        this.queen_pos[line] = new_column;
        int cnt = 0;
        for(int i=0;i<this.size;i++)
            if(this.queen_pos[line] == this.queen_pos[i] && i != line)
                cnt++;
        
        int x = line, y = new_column;

        while(x > 0 && y > 0) {
            x--;
            y--;
        }
        
        while(x < this.size && y < this.size) {
            if(this.queen_pos[x] == y && x != line) cnt++;
            x++;
            y++;
        }

        x = line;
        y = new_column;
        
        while(x > 0 && y < this.size - 1) {
            x--;
            y++;
        }
        
        while(x < this.size && y >= 0) {
            if(this.queen_pos[x] == y && x != line) cnt++;
            x++;
            y--;
        }

        
        this.queen_pos[queen_p] = column;
        return cnt;
    }

    public void updatePosition(int line, int column) {
        this.stats[line][column] = 0;
        for(int i=0;i<this.size;i++) this.stats[line][column] += this.getQueenPairs(i, this.queen_pos[i]);
        this.stats[line][column] /= 2;
    }

    public void updateTabuleiro() {
        for(int i=0;i<this.size;i++)
            for(int j=0;j<this.size;j++) {
                int old_position = this.queen_pos[i];
                this.movQueenTo(i, j);
                this.updatePosition(i, j);
                this.movQueenTo(i, old_position);
            }
    }

    //

    public void SimulatedAnnealing(int max_j) {
        this.updateTabuleiro();
        int line = 0, column = 0;

        int j = 0;

        while(j< max_j) {
            int max_iters    = 10000;
            int max_sucessos = 1000;
            
            int iter     = 0;
            int sucessos = 0;

            while(iter <= max_iters && sucessos <= max_sucessos) {
                line        = this.gen.nextInt(this.size);
                column      = this.gen.nextInt(this.size);

                int next    = this.stats[line][column];
                int current = this.stats[0][this.queen_pos[0]];
                
                int delta   = next - current;

                double rd   = this.gen.nextDouble(1);

                if(delta < 0 || rd <= Math.exp(-delta/this.Temp)) { // Sucesso!!
                    sucessos++;
                    this.movQueenTo(line, column);
                    this.updateTabuleiro();
                }
            }

            this.Temp *= this.alfa;
            j++;
        }

    }

    public String getTabuleiro() {
        String ret = "";

        for(int i=0;i<this.size;i++) {
            for(int j=0;j<this.size;j++) {
                ret += (this.queen_pos[i] == j ? '1' : '0');// + " " + Integer.toString(this.stats[i][j]);
                ret += " ";
            } 
            ret += "\n";
        }

        return ret;
    }

    public static void main(String[] args) {
        Tabuleiro a = new Tabuleiro(6);
        System.out.println(a.getTabuleiro());
        a.SimulatedAnnealing(2000);
        System.out.println(a.getTabuleiro());
    }
}