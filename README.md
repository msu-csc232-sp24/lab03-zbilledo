# LAB03: Pointers, Polymorphism, and Memory Allocation

## Objectives

In today's lab, we look to gain further understanding of pointers,
polymorphism and memory allocation. We do this by creating a simple
interface with multiple implementations. By considering a collection of
pointers to the simple interface, we will notice different behaviors from
the same message, i.e., we demonstrate polymorphic behavior in C++.

## Background Reading

The basis for the concepts covered in this lab is _C++ Interlude 2: Pointers,
Polymorphism, and Memory Allocation_.

## Tasks

This lab, like most others, requires the completion of three tasks:

1. Create an interface (the `Dog` ADT)
2. Implement this interface in multiple ways (`Yorkie` and `GreatDaehn`)
3. Demonstrate polymorphic behavior

### Task 1: Create a Dog interface

We begin with a simple ADT. We shall model a dog. In our simple model, a dog
can respond to two messages:

1. speak
2. sit

To implement this ADT, we merely encasulate these as operations in an
abstract class named `Dog`. As an interface, each operation is declared as a
_pure virtual_ method.

```c++
/**
 * @brief A simple model of a Dog.
 */
class Dog
{
public:
    /**
     * @brief Command this Dog to speak.
     * @return A translation of what this Dog says in response.
     */
    virtual std::string speak() const = 0;

    /**
     * @brief Command this Dog to sit.
     * @post  A message is inserted into the standard output stream.
     */
    virtual void sit() const = 0;

    /**
     * Virtual Dog destructor.
     */
    virtual ~Dog() = default;
};
```

Add this class declaration in the space provided in [include/csc232.h]
(include/csc232.h). When you are done, also toggle the state of the
`FINISHED_PART_1` macro from `FALSE` to `TRUE`.

Save the changes in your file. Stage your changes (using the `git add`
command), then commit them (using the `git commit` command), and push your
changes to GitHub (using the `git push` command). When you commit your
changes, be sure to write a meaningful commit message.

### Task 2: Implement the Dog interface

Now that we have an interface, it's time to implement it. Even though we can
legitimately create a pointer to this interface, we just can't create an
actual `Dog` object for that pointer. This, of course, is because it has no
definitions behind the declared operations. In task 2, we create two
different implementations of this `Dog` interface. Because we will provide
implementation details (i.e., definitions for the inherited operations), we
_will_ be able to create such objects. Further, we can store the addresses
of these objects in our interface (`Dog`) pointer.

#### Task 2a: A Yorkie IS_A Dog

Yorkie is short for [Yorkshire Terrier](https://en.wikipedia.
org/wiki/Yorkshire_Terrier). They're very cute dogs, but can be rather
mouthy at times. But firstly, we must recognize a very obvious relationship:
A `Yorkie` _is a_ `Dog`. This is one very good indicator that there is a
chance for using inheritance. Inheritance captures the essence of the _is a
(n)_ relationship.

The following declaration captures this:

```c++
class Yorkie : public Dog
{
public:
    Yorkie(const std::string& dogs_name);
    std::string speak() const override;
    void sit() const override;
private:
    std::string name;
};
```

Add this class declaration in the space provided in [include/csc232.h]
(include/csc232.h). Save your changes and stage the file for commit. Make a
commit and push the change to GitHub.

Research has shown that when told to speak, Yorkies do so, and so very
loudly, despite their small size. When put through our translation system,
it was found that the first response to the "speak" command is to say (again,
very loudly): "Did you say speak?". Since our operation requires that we
return a translated string in response, implement this method to reply with
that string, in ALL CAPS.

Following the above class declaration in [include/csc232.h](include/csc232.h)
, _implement_ the methods as follows. (_For simplicity, we are keeping the
declaration and definition here in the same file. We split them up just to
practice good habits on the separation of concerns_.)

```c++
Yorkie::Yorkie(const std::string& dogs_name) : name{ dogs_name }
{
    std::cout << "A Yorkie named " << name << " was just created." << std::endl;
}

std::string Yorkie::speak() const
{
    std::string response{ "DID YOU SAY SPEAK?" };
}

void Yorkie::sit() const
{
    std::cout << "A Yorkie named " << name << " just sat down." << std::endl;
}
```

Save your changes and stage the file for commit. Make a commit and push the
change to GitHub.

#### Task 2b: A Great Daehn IS_A Dog

The Great Daehn is a special breed of dog. It is quite dopey. But again, we
must recognize a very obvious relationship: A `GreatDaehn` _is a_ `Dog`.
Thus, again, declare and implement the `Dog` interface in a class named
`GreatDaehn` as you did above for the `Yorkie` class. However, there are
some differences between these two species. Research has shown that the
first response to the "speak" command here is "What?". Be sure you override
the `speak()` operation accordingly for this class.

With respect to sitting, implement the behavior in a manner analogous to the
`Yorkie` class substituting `GreatDaehn` for `Yorkie`.

When you are done, also toggle the state of the `FINISHED_PART_2` macro from
`FALSE` to `TRUE`.

### Task 3: Demonstrate Polymorphic Behavior

Finally, polymorphic behavior is observed by creating an array of `Dog`
pointers and sending the various messages they can respond to and note the
differences in behavior. For example, consider the code shown in [src/main/cpp/main.cpp](src/main/cpp/main.cpp)

Modify the `main()` method in [src/main/cpp/main.cpp](src/main/cpp/main.cpp) so that
it invokes the `demo()` function. See what is sent to the standard console
window. Is it what you expect?

## Submission Details

As usual, prior to submitting your assignment to Microsoft Teams, be sure
that you have committed and pushed your final changes to GitHub. If you have
not done so already, create a **pull request** that seeks to merge your
`develop` branch into your `trunk` branch.  Submit the URL of your
assignment _repository_ (i.e., _not_ the URL of the pull request) as a Text
Submission in Microsoft Teams. Please note: the timestamp of the submission on
Microsoft Teams is used to assess any late penalties if and when warranted.

Finally, be sure that you **do not merge your pull request until it has been
approved by one of the assigned reviewers**.

### Due Date

Your Microsoft Teams submission is due by the end of your lab period. Write
permissions to your repo expire at 23:59 on Saturday 10-February 2024.

### Grading Rubric

This assignment is worth **3 points**.

| Criteria           | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                        |
|--------------------|------------------------------|-------------------------------------|-------------------------------------|------------------------------------------------|
| Pull Request (20%) | Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted       |
| Code Style (20%)   | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present |
| Correctness^ (60%) | All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass           |

^ _The Catch2 Test unit runner, if appropriate, will calculate the
correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24-hour period following the due date, this lab will be
  penalized 0.6 point meaning the grading starts at 2.4 (out of 3 total possible) points.
* In the second 24-hour period following the due date, this lab will be
  penalized 1.2 points meaning the grading starts at 1.8 (out of 3 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 3 possible points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not
have been specifically authorized by the copyright owner. This material is
available in an effort to explain issues relevant to the course or to
illustrate the use and benefits of an educational tool. The material
contained in this repository is distributed without profit for research and
educational purposes. Only small portions of the original work are being
used and those could not be used to easily duplicate the original work.

This constitutes a 'fair use' of any such copyrighted material (referenced
and provided for in section 107 of the US Copyright Law).

If you wish to use any copyrighted material from this repository for
purposes that go beyond 'fair use', you must obtain expressed permission
from the copyright owner.
