#pragma once

#include <cstdint>

template <typename int_type>
struct pos2d_t{

    pos2d_t (int_type x, int_type z): x(x), z(z){}
    pos2d_t (): pos2d_t(0, 0){}

    int_type x, z;

    friend bool operator==(const pos2d_t<int_type>& A, const pos2d_t<int_type>& B){
        return A.x == B.x && A.z == B.z;
    }

    friend bool operator!=(const pos2d_t<int_type>& A, const pos2d_t<int_type>& B){
        return !(A == B);
    }

};

template <typename int_type>
struct pos3d_t{

    pos3d_t (int_type x, int_type y, int_type z): x(x), y(y), z(z){}
    pos3d_t (): pos3d_t(0, 0, 0){}

    int_type x, y, z;

    friend bool operator==(const pos3d_t<int_type>& A, const pos3d_t<int_type>& B){
        return A.x == B.x && A.y == B.y && A.z == B.z;
    }

    friend bool operator!=(const pos3d_t<int_type>& A, const pos3d_t<int_type>& B){
        return !(A == B);
    } 

};



using abs_pos = pos3d_t<uint64_t>;