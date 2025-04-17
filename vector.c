#include "lib/Vector.h"




Vector(int, Int_Vector)


Vector(Int_Vector *, _2D_Int_vector)

int main(int argc, char const* argv[]) {
    _2D_Int_vector * vec_2d = create__2D_Int_vector(free_Int_Vector);
    Int_Vector * vec = create_Int_Vector(NULL);
    push_Int_Vector(vec, 1);
    push__2D_Int_vector(vec_2d, vec);
    printf("%d, allocated=%zu, length=%zu\n", index_Int_Vector(index__2D_Int_vector(vec_2d, 0), 0), vec->allocated, vec->length);




    return 0;
}
