// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

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
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess.Equals(HiddenWord))
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
    }
    else
    {
        --Lives;
        if (Guess.Len() == HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i letters"), HiddenWord.Len());
        }
        PrintLine(TEXT("You have %i lives left"), Lives);
        if (Lives == 0)
        {
            PrintLine(TEXT("You have lost.."));
            EndGame();
        }
    }
}