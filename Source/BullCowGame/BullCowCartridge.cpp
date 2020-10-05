// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();

}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again.."));
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("self");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Welcome to Bull Cow Game"));
    PrintLine(TEXT("The hidden word is %i letters.\nYou have %i lives"), HiddenWord.Len(), Lives); // word length is a magic number
    PrintLine(TEXT("What is your guess?"));

    const TCHAR HW[] = TEXT("self");
    PrintLine(TEXT("Char 1 is: %c"), HW[0]);
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess.Equals(HiddenWord))
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
    }
    if (Guess.Len() == HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters\nTry again!"), HiddenWord.Len());
    }
    if (!IsIsogram(Guess))
    {
        return;
    }
    --Lives;
    PrintLine(TEXT("You have %i lives left"), Lives);
    if (Lives == 0)
    {
        PrintLine(TEXT("You have lost..\nThe correct word was: %s"), HiddenWord);
        EndGame();
        return;
    }
}
bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            } 
        }
    }
    return true;
}
