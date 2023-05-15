#include "Form.hpp"

Form::Form()
{
}

Form::~Form()
{
}

Form::Form(std::string name, int grade): _form_name(name), _form_grade(grade)
{
}

Form::Form(Form &other)
{
	*this = other;
}

Form &Form::operator=(Form const &other)
{
	this->_form_grade = other._form_grade;
	this->_signed = other._signed;
	return (*this);
}

const std::string Form::get_form_name()
{
	return _form_name;
}

bool Form::is_signed()
{
	return _signed;
}

const int Form::get_form_grade()
{
	return _form_grade;
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	
}
