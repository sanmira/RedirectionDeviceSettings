package org.qtproject.qt5;
import android.provider.DocumentsProvider;
import android.content.Intent;
import org.qtproject.qt5.android.bindings.QtActivity;
import android.app.Activity;
import android.provider.Settings;
import android.content.pm.PackageManager;
import android.Manifest;
import java.util.Calendar;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.OutputStream;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import android.os.ParcelFileDescriptor;
import android.net.Uri;
import org.qtproject.qt5.NativeCalls;

public class AppActivity extends QtActivity
{
    private final int RW_EXTERNAL_STORAGE_PERMISSIONS = 41;
    private final int WRITE_REQUEST_CODE = 42;
    private final int READ_REQUEST_CODE = 43;

    private String m_dataToWrite;

    public void create_file(String dataToWrite)
    {
        m_dataToWrite = dataToWrite;
        Intent intent = new Intent(Intent.ACTION_CREATE_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);

        intent.setType("text/plain");

        intent.putExtra(Intent.EXTRA_TITLE, "settings.txt");

        startActivityForResult(intent, WRITE_REQUEST_CODE);
    }

    private void write_file(Uri uri)
    {
        try
        {
            ParcelFileDescriptor pfd = this.getContentResolver().openFileDescriptor(uri, "w");
            OutputStream oStream = new FileOutputStream(pfd.getFileDescriptor());
            oStream.write(m_dataToWrite.getBytes());
            oStream.close();
            pfd.close();
            NativeCalls.io_success();
        } catch (FileNotFoundException e)
        {
            e.printStackTrace();
            NativeCalls.io_fail();
        } catch (IOException e)
        {
            e.printStackTrace();
            NativeCalls.io_fail();
        }
    }

    public void open_file()
    {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);

        intent.setType("text/plain");

        startActivityForResult(intent, READ_REQUEST_CODE);
    }

    public void read_file(Uri uri)
    {
        try
        {
            ParcelFileDescriptor pfd = this.getContentResolver().openFileDescriptor(uri, "r");
            InputStream iStream = new FileInputStream(pfd.getFileDescriptor());
            BufferedReader reader = new  BufferedReader(new InputStreamReader(iStream));
            String line;
            line = reader.readLine();
            int count;
            try
            {
                count = Integer.parseInt(line);
            } catch (NumberFormatException e)
            {
                e.printStackTrace();
                NativeCalls.io_fail();
                return;
            }
            NativeCalls.clear_subscribers_list();
            while ((line = reader.readLine()) != null)
            {
                NativeCalls.new_line(line);
            }
            iStream.close();
            pfd.close();
            NativeCalls.io_success();
        } catch (FileNotFoundException e)
        {
            e.printStackTrace();
            NativeCalls.io_fail();
            return;
        } catch (IOException e)
        {
            e.printStackTrace();
            NativeCalls.io_fail();
            return;
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        if ((requestCode == WRITE_REQUEST_CODE) && (resultCode == Activity.RESULT_OK))
        {
            Uri uri = null;
            if (data != null)
            {
                uri = data.getData();
                write_file(uri);
            }
        } else if ((requestCode == READ_REQUEST_CODE) && (resultCode == Activity.RESULT_OK))
        {
            Uri uri = null;
            if (data != null)
            {
                uri = data.getData();
                read_file(uri);
            }
        } else
        {
            NativeCalls.io_fail();
        }
    }

    public void requestStorageRWPermissions()
    {
        requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE, Manifest.permission.READ_EXTERNAL_STORAGE}, RW_EXTERNAL_STORAGE_PERMISSIONS);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults)
    {
        switch (requestCode)
        {
            case RW_EXTERNAL_STORAGE_PERMISSIONS:
            {
                if ((grantResults.length > 0) && (grantResults[0] == PackageManager.PERMISSION_GRANTED))
                {
                    //->...
                } else
                {
                    Intent intent = new Intent();
                    intent.setAction(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
                    Uri uri = Uri.fromParts("package", getPackageName(), null);
                    intent.setData(uri);
                    startActivity(intent);
                }
            }
        }
    }
}
