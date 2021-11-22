#ifndef COMMON_MATRIX4_H
#define COMMON_MATRIX4_H


class Matrix4 {
    public:
		float _11, _12, _13, _14;
		float _21, _22, _23, _24;
		float _31, _32, _33, _34;
		float _41, _42, _43, _44;

		Matrix4()
		{

		}

		Matrix4(float c)
		{
			this->_11 = c;
			this->_12 = c;
			this->_13 = c;
			this->_14 = c;
			this->_21 = c;
			this->_22 = c;
			this->_23 = c;
			this->_24 = c;
			this->_31 = c;
			this->_32 = c;
			this->_33 = c;
			this->_34 = c;
			this->_41 = c;
			this->_42 = c;
			this->_43 = c;
			this->_44 = c;
		}
    };


#endif // COMMON_MATRIX4_H
