#include"../include/math/Matrix4x4.h"
#include"../include/math/Vector3.h"

namespace nano { namespace math {
	
	Matrix4x4::Matrix4x4()
	{
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}
	}

	Matrix4x4::Matrix4x4(float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}
		
		//       y     x
		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4x4& Matrix4x4::Multiply(const Matrix4x4& other) 
	{
		Matrix4x4 result;

		// Loop through the matrix
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				// Multiplying appropiate values together

				float sum = 0.0f;
				for (int e = 0; e < 4; e++) {
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				elements[x + y * 4] = sum;
			}
		}

		return *this;
	}

	Matrix4x4 Matrix4x4::Scale(const Vector3& scale)
	{
		Matrix4x4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

	Matrix4x4 Matrix4x4::Rotation(float angle, const Vector3& axis)
	{
		Matrix4x4 result(1.0f);

		float r = (angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = x * y * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;

		return result;
	}

	Matrix4x4 Matrix4x4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		Matrix4x4 result(1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right - left);

		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

		result.elements[2 + 2 * 4] = 2.0f / (near - far);
		 //             y     x
		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}

	Matrix4x4 Matrix4x4::Identity()
	{
		return Matrix4x4(1.0f);
	}

	Matrix4x4 Matrix4x4::Translation(const Vector3& translation)
	{
		// Create the empty identity matrix
		Matrix4x4 result = Matrix4x4::Identity();

		// Translate the matrix by translation vector
		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}

} }
