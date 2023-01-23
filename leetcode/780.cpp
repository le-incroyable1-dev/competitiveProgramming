class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        
        while(sx < tx && sy < ty){

            if(tx < ty)
            ty %= tx;
            else
            tx %= ty;

        }

        if(sx == tx && sy <= ty && (ty-sy)%tx == 0)
        return true;

        if(sy == ty && sx <= tx && (tx-sx)%ty == 0)
        return true;

        return false;
        

    }
};
