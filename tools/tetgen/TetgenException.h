#pragma once

#include <Core/Exception.h>
#include <sstream>

class TetgenException : public PyMeshException {
    public:
        TetgenException(int error_code) :
            m_error_code(error_code), PyMeshException("") {}

        virtual ~TetgenException() throw() {}
        virtual const char* what() const throw() {
            std::stringstream err_msg;
            err_msg << "Tetgen Error (" << m_error_code << "): ";
            switch (m_error_code) {
                case 1:
                    err_msg << "Out of memory.";
                    break;
                case 2:
                    err_msg << "Tetgen internal bug. Report it to Hang Si.";
                    break;
                case 3:
                    err_msg << "Self-intersection.";
                    break;
                case 4:
                    err_msg << "Very small input feature detected.";
                    break;
                case 5:
                    err_msg << "Two very close faces detected.";
                    break;
                case 10:
                    err_msg << "An input error detected.";
                    break;
                default:
                    err_msg << "Unknow tetgen error";
                    break;
            }
            return err_msg.str().c_str();
        }

    private:
        int m_error_code;
};
