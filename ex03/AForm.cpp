#include "AForm.hpp"

AForm::AForm(): _form_name("name"), _grade_sign(150), _grade_exec(150)
{
	set_is_signed(false);
}

AForm::~AForm()
{

}

AForm::AForm(std::string name, int grade, int exec): _form_name(name), _grade_sign(grade), _grade_exec(exec)
{
	set_is_signed(false);
	if (_grade_sign < 1 || _grade_exec < 1)
		throw	GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw 	GradeTooLowException();
}

AForm::AForm(AForm &other):_form_name(other._form_name), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec)
{
	*this = other;
}

AForm &AForm::operator=(AForm const &other)
{	
	this->_signed = other._signed;
	return (*this);
}

std::string AForm::get_form_name() const
{
	return _form_name;
}

bool AForm::is_signed() const
{
	return _signed;
}

void AForm::set_is_signed(bool is)
{
	_signed = is;
}

int AForm::get_grade_sign() const
{
	return _grade_sign;
}

int AForm::get_grade_exec() const
{
	return  _grade_exec;
}

void AForm::beSigned(Bureaucrat &bureau)
{
	if (is_signed())
		throw std::invalid_argument("already signed");
	if (bureau.getgrade() <= _grade_sign)
		set_is_signed(true);
	else
		throw GradeTooLowException();
	
}

std::ostream &operator<<(std::ostream &stream, AForm  &form)
{
	stream << form.get_form_name()<<" "<<form.get_grade_sign()<<" "<<form.get_grade_exec()<<" "<<form.is_signed();
	return stream;
}

