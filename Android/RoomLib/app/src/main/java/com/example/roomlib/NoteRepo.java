package com.example.roomlib;

import android.app.Application;
import android.os.AsyncTask;

import androidx.lifecycle.LiveData;

import java.util.List;

public class NoteRepo {
    public NotesDao noteDao;
    public LiveData<List<Note>> noteList;
    public NoteRepo (Application application)
    {
        NoteDatabase noteDatabase=NoteDatabase.getInstance(application);
        noteDao=noteDatabase.noteDao();
        noteList=noteDao.getAllData();

    }
    public void insertData(Note note){new InsertTask(noteDao).execute(note);};
    public void updateData(Note note){new UpdateTask(noteDao).execute(note);};
    public void deleteData(Note note){new DeleteTask(noteDao).execute(note);};
    public LiveData<List<Note>> getAllData()
    {
        return noteList;
    }

    private static class InsertTask extends AsyncTask<Note,Void,Void>
    {
        private final NotesDao noteDao;

        public InsertTask(NotesDao noteDao)
        {

            this.noteDao = noteDao;
        }


        @Override
        protected Void doInBackground(Note... notes) {
            noteDao.insert(notes[0]);
            return null;
        }
    }
    private static class DeleteTask extends AsyncTask<Note,Void,Void>
    {
        private final NotesDao noteDao;

        public DeleteTask(NotesDao noteDao)
        {

            this.noteDao = noteDao;
        }


        @Override
        protected Void doInBackground(Note... notes) {
            noteDao.delete(notes[0]);
            return null;
        }
    }
    private static class UpdateTask extends AsyncTask<Note,Void,Void>
    {
        private final NotesDao noteDao;

        public UpdateTask(NotesDao noteDao)
        {

            this.noteDao = noteDao;
        }


        @Override
        protected Void doInBackground(Note... notes) {
            noteDao.update(notes[0]);
            return null;
        }
    }
}