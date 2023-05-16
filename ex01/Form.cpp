#include "Form.hpp"

Form::Form(): _form_name("name"), _grade_sign(150), _execute_it(150)
{
	set_is_signed(false);
}

Form::~Form()
{

}

Form::Form(std::string name, int grade, int exec): _form_name(name), _grade_sign(grade), _execute_it(exec)
{
	set_is_signed(false);
	if (_grade_sign < 1 || _execute_it < 1)
		throw	GradeTooHighException();
	else if (_grade_sign > 150 || _execute_it > 150)
		throw 	GradeTooLowException();
}

Form::Form(Form &other):_form_name(other._form_name), _grade_sign(other._grade_sign), _execute_it(other._execute_it)
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

void Form::set_is_signed(bool is)
{
	_signed = is;
}

int Form::get_grade_sign()
{
	return _grade_sign;
}

int Form::get_execute_it()
{
	return _execute_it;
}

void Form::beSigned(Bureaucrat &bureau)
{
	if (is_signed())
		throw std::invalid_argument("already signed");
	if (bureau.getgrade() <= _grade_sign)
		set_is_signed(true);
	else
		throw GradeTooLowException();
	
}

std::ostream &operator<<(std::ostream &stream, Form  &form)
{
	stream << form.get_form_name()<<" "<<form.get_grade_sign()<<" "<<form.get_execute_it()<<" "<<form.is_signed();
	return stream;
}
