//
// Created by youngliqui on 22.02.2024.
//

#ifndef OOP_4TERM_CODER_H
#define OOP_4TERM_CODER_H

#endif //OOP_4TERM_CODER_H


class Coder{
public:
    static int encrypt(int value, int key);
    static int decrypt(int encryptedValue, int key);
};

int Coder::encrypt(int value, int key) {
    return value ^ key;
}

int Coder::decrypt(int encryptedValue, int key) {
    return encryptedValue ^ key;
}
