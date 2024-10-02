#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
struct point_t {
    int x, y;
};
struct triangle_t {
    struct point_t pts[3];
};

int double_area(struct triangle_t tr){
    int det = (tr.pts[0].x * tr.pts[1].y * 1) + 
        (tr.pts[0].y * 1 * tr.pts[2].x) +   
        (1 * tr.pts[1].x * tr.pts[2].y) - 
        (tr.pts[0].y * tr.pts[1].x * 1) -
        (tr.pts[0].x * 1 * tr.pts[2].y) - 
        (1 * tr.pts[1].y * tr.pts[2].x);
    if(det < 0)det = det * (-1);
    return det;
}

int double_area_p(struct triangle_t* tr){
    int det = tr->pts[0].x * tr->pts[1].y * 1 + 
        tr->pts[0].y * 1 * tr->pts[2].x +   
        1 * tr->pts[1].x * tr->pts[2].y - 
        1 * tr->pts[1].y * tr->pts[2].x - 
        tr->pts[0].x * 1 * tr->pts[2].y - 
        tr->pts[0].y * tr->pts[1].x * 1;
        return det;
    }


int main() {
    struct triangle_t tr;
    int res = scanf("%d%d%d%d%d%d", &tr.pts[0].x, &tr.pts[0].y,
                                    &tr.pts[1].x, &tr.pts[1].y, 
                                    &tr.pts[2].x, &tr.pts[2].y);
    if(res!=6){
        printf("%s", "Wrong input");
        abort();
    }
    printf("%d", double_area(tr));
}
