#include "Form.hpp"

Form::Form()
{
	_signed = false;
}

Form::~Form()
{

}

Form::Form(std::string name, int grade): _form_name(name), _grade_sign(grade)
{
	_signed = false;
	if (_grade_sign < 1)
		throw	GradeTooHighException();
	else if (_grade_sign > 250)
		throw 	GradeTooLowException();
}

Form::Form(Form &other)
{
	*this = other;
}

Form &Form::operator=(Form const &other)
{
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

const int Form::get_grade_sign()
{
	return _grade_sign;
}

const int Form::get_execute_it()
{
	return _execute_it;
}

void Form::beSigned(Bureaucrat &bureau)
{
	if (bureau.getgrade() <= _grade_sign)
		_signed = true;
	else
		throw GradeTooLowException();
	
}

std::ostream &operator<<(std::ostream &stream, Form  &form)
{
	stream << form.get_form_name()<<" "<<form.get_grade_sign()<<" "<<form.get_execute_it()<<" "<<form.is_signed();
	return stream;
}
