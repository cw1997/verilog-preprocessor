//
// Created by 86759 on 2021/6/22.
//

#ifndef TEST_TESTING_UTILS_H
#define TEST_TESTING_UTILS_H

//#include <vector>

//template<typename T> void vector_equal(std::vector<T> x, std::vector<T> y);


#define VECTOR_EQUAL(X, Y) \
    ASSERT_EQ(X.size(), Y.size()) << "Vectors x and y are of unequal length";\
    for (int i = 0; i < X.size(); ++i) {\
        EXPECT_EQ(X[i], Y[i]) << "Vectors x and y differ at index " << i;\
    }


#endif //TEST_TESTING_UTILS_H
